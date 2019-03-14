package fileop;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.ObjectOutputStream.PutField;

public class op {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			PrintWriter out = new PrintWriter(
					new BufferedWriter(
							new OutputStreamWriter(
									new FileOutputStream("aa.txt"))));
			out.println("ojbkjjj");
			out.close();
			BufferedReader in = new BufferedReader(  
					new InputStreamReader( 
							new FileInputStream("aa.txt"))); 
			String line;
			try {
				while((line = in.readLine()) != null) {
					System.out.println(line);
				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
