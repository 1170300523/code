package adapter;

import javax.imageio.IIOException;
import java.io.FileWriter;
import java.io.IOException;

public class CD1 implements CD {
    @Override
    public void play() {
        System.out.println("play CD1");
    }

    public static void main(String[] args) {
        try {
        FileWriter fileWriter = new FileWriter("1.txt");
        fileWriter.write("kkkjjjj");
        fileWriter.write("koko");
        fileWriter.close();
        }catch (IOException e){
            System.out.println("no file");
        }
    }
}
