import java.io.*;
import java.util.*;

public class Main {

    public static boolean isSame(List<Integer> a, List<Integer> b) {
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i) != b.get(i)) return false;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        int[] arrA = new int[n];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            arrA[i] = Integer.parseInt(st.nextToken());
        }

        int m = Integer.parseInt(br.readLine());
        List<Integer> arrB = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            arrB.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(arrB);

        List<Integer> diff = new ArrayList<>();
        for (int i = 0; i < m-1; i++) {
            diff.add(arrB.get(i+1)-arrB.get(i));
        }

        // index i부터 길이가 k인 부분 수열을 만든다
        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i <= n-m; i++) {
            List<Integer> subArr = new ArrayList<>();
            for (int j = i; j < i+m; j++) {
                subArr.add(arrA[j]);
            }

            Collections.sort(subArr);

            List<Integer> subArrDiff = new ArrayList<>();
            for (int j = 0; j < subArr.size()-1; j++) {
                subArrDiff.add(subArr.get(j+1)-subArr.get(j));
            }

            if (isSame(subArrDiff, diff)) answer.add(i);
        } 

        System.out.println(answer.size());
        for (int elem : answer) System.out.println(elem+1);
    }
}