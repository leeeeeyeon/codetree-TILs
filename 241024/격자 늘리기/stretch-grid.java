import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        ArrayList<String> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            board.add(str);
        }

        for (String str : board) {
            String temp = "";
            for (int i = 0; i < str.length(); i++) {
                for (int j = 0; j < k; j++) {
                    temp += str.charAt(i);
                }
            }
            
            for (int i = 0; i < k; i++) {
                System.out.println(temp);
            }
        }
    }
}