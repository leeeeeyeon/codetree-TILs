import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        String inputA = br.readLine();
        String inputB = br.readLine();

        String[] arrA = inputA.split(" ");
        String[] arrB = inputB.split(" ");

        ArrayList<Integer> result = new ArrayList<>();
        for (String elem : arrA) {
            result.add(Integer.parseInt(elem));
        }
        for (String elem : arrB) {
            result.add(Integer.parseInt(elem));
        }

        Collections.sort(result);
        for (int elem : result) {
            System.out.print(elem + " ");
        }
    }
}