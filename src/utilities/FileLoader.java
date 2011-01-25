package utilities;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class FileLoader {
    public String load(String path) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(path));
            return br.readLine();
        } catch (FileNotFoundException e) {
            System.out.println("Error: File<" + path + "> cannot be found.");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        return null;
    }
}
