import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class HardTester {
	private static final int sSampleSize = 500;
	private static final int sThreadCount = 4;
	private static final int sTestPerThread = 100;
	private static final int sTestCount = sThreadCount * sTestPerThread;
	private static final Object sLock = new Object();
	private static int sSuccessCount = 0;
	private static int sAverage = 0;
	private static int sMax = 0;
	private static int sMin = Integer.MAX_VALUE;

	public static void shuffle(String[] array) {
		Random rand = new Random();

		for (int i = 0; i < array.length + 10; ++i) {
			var idx0 = rand.nextInt(array.length);
			var idx1 = rand.nextInt(array.length);

			var tmp = array[idx0];
			array[idx0] = array[idx1];
			array[idx1] = tmp;
		}
	}

	public static boolean execPushSwap(int size) {
		String[] sample = new String[size];

		for (int i = 0; i < size; ++i) {
			sample[i] = Integer.toString(i);
		}

		shuffle(sample);

		return execPushSwap(sample);
	}

	public static boolean execPushSwap(String[] values) {
		var rt = Runtime.getRuntime();
		var pushSwap = "./push_swap";
		var checker = "./checker";

		String[] cmdArray = new String[values.length + 1];
		cmdArray[0] = pushSwap;
		System.arraycopy(values, 0, cmdArray, 1, values.length);

		try {
			var pushSwapProcess = rt.exec(cmdArray);

			cmdArray[0] = checker;
			var checkerProcess = rt.exec(cmdArray);
			int instructionCount = 0;

			var noTimeout = pushSwapProcess.waitFor(12, TimeUnit.SECONDS);

			if (!noTimeout) {
				System.out.println(Thread.currentThread().getId() + " - FAILED - timeout");
				return false;
			}

			var exitCode = pushSwapProcess.exitValue();

			if (exitCode != 0) {
				System.out.println(Thread.currentThread().getId() + " - FAILED - returned " + exitCode);
				
				for (var s: cmdArray) {
					System.out.println("arg: " + s);
				}

				System.out.println("---------------- LOG ----------------");
				try (Scanner sc = new Scanner(new BufferedInputStream(pushSwapProcess.getErrorStream()))) {
					while (sc.hasNextLine()) {
						String line = sc.nextLine();

						System.out.println(line.getBytes(StandardCharsets.US_ASCII));
						System.out.println('\n');
						++instructionCount;
					}
				}
				System.out.println("---------------- END OF LOG ----------------");
				return false;
			}

			try (Scanner sc = new Scanner(new BufferedInputStream(pushSwapProcess.getInputStream()))) {
				var checkerOut = new BufferedOutputStream(checkerProcess.getOutputStream());
				while (sc.hasNextLine()) {
					String line = sc.nextLine();

					checkerOut.write(line.getBytes(StandardCharsets.US_ASCII));
					checkerOut.write('\n');
					++instructionCount;
				}
				checkerOut.flush();
				checkerOut.close();
			}

			int ret = checkerProcess.getInputStream().read();
			if (ret == -1) {
				System.out.println(Thread.currentThread().getId() + " - FAILED - checker input stream error");
				return false;
			}

			if (ret != 'O') {
				System.out.println(Thread.currentThread().getId() + " - FAILED - KO on checker");
				return false;
			}
			System.out.println(Thread.currentThread().getId() + " - SUCCEED with " + instructionCount + " instruction(s)");

			synchronized (sLock) {
				if (sMax < instructionCount)
					sMax = instructionCount;
				if (sMin > instructionCount)
					sMin = instructionCount;

				sSuccessCount += 1;
				if (sSuccessCount != 1) {
					sAverage += (instructionCount - sAverage) / sSuccessCount;
				} else {
					sAverage += instructionCount;
				}

			}
			return true;
		} catch (IOException | InterruptedException e) {
			System.out.println(Thread.currentThread().getId() + " - " + e.getClass().getSimpleName() + ": " + e.getMessage());
		}
		return false;
	}

	public static void main(String[] args) {
		Thread[] threads = new Thread[sThreadCount];

		for (int i = 0; i < threads.length; ++i) {
			threads[i] = new Thread(() -> {
				for (int j = 0; j < sTestPerThread; ++j) {
					execPushSwap(sSampleSize);
				}
			});
			threads[i].start();
		}

		for (int i = 0; i < threads.length; ++i) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		System.out.println("Success: " + sSuccessCount + "/" + (sTestCount) + " (" + ((sSuccessCount * 100) / sTestCount) + "%)");
		System.out.println("Average: " + sAverage + " instructions");
		System.out.println("Minimum: " + sMin + " instructions");
		System.out.println("Maximum: " + sMax + " instructions");
	}
}