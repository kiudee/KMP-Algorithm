import utilities.FileLoader;

public class Runner {
    public static void main(String[] args) {
        FileLoader fl = new FileLoader();
        String string1 = fl.load(args[0]);
        String string2 = fl.load(args[1]);
    }
}
