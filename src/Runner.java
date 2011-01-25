import utilities.FileLoader;
import utilities.IAlgorithm;
import utilities.Verifier;

public class Runner {
    public static void main(String[] args) {
        FileLoader fl = new FileLoader();
        String T1 = fl.load(args[0]);
        String T2 = fl.load(args[1]);

        // Generate the solution using our algorithm
        // Input the algorithm here:
        IAlgorithm algo = new Verifier();
        String result = algo.run(T1, T2);
        System.out.println(result);

        // Generate the verification solution:
        IAlgorithm verificator = new Verifier();
        String correct = verificator.run(T1, T2);
        if (!result.equals(correct)) {
            System.out.println("Error: Result and Solution do not match!");
        }
    }
}
