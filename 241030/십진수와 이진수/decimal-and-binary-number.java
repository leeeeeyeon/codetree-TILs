import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        Long num = Long.parseLong(str, 2);

        System.out.println(Long.toBinaryString(num * 17));
    }
}