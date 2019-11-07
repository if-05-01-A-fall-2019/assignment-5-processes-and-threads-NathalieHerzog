/***************************************************
 * Programname:             SimpleShell         	 	    
 * Author:		    Nathalie Herzog
 * ID:			    09
 * Class:		    3AHIF
 * Date:		    7th of Nov
 * -------------------------------------------------
 * Description:
 * Implement a simple shell that behaves similarly
 * to the UNIX shell.
 * *************************************************
*/

package simpleshell;

import java.io.InputStream;
import java.util.Scanner;

/**
 *
 * @author NathaieHerzog
 */
public class SimpleShell {

   public static void main(String[] args){
       int exit = 0;
       int output = 0;
       String delimiter = "&";
       
        System.out.print("> ");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        
        String[] parts = input.split(delimiter);      
              
        for (String part : parts) {
            try {
                Process process = Runtime.getRuntime().exec(part);  
                
                InputStream stream = process.getInputStream();
                process.waitFor();
                output = stream.read();
                
                while (output != -1) {
                    //outputs the contents of the stream until it's end is reached
                    System.out.print((char) output);
                    output = stream.read();
                }
                
                System.out.println("successful");
            }
            catch (Exception e)
            {
                System.out.println("error");
            }

        }
    }    
}

