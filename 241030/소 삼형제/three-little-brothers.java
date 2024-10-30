import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        HashMap<String, Integer> hm = new HashMap<>();
        for (int i = 0; i < n; i++) {
            List<String> arr = new ArrayList<>();

            StringTokenizer st = new StringTokenizer(br.readLine());
            arr.add(st.nextToken());
            arr.add(st.nextToken());
            arr.add(st.nextToken());

            Collections.sort(arr);

            String result = "";
            for (String name : arr) {
                result += name;
            }

            int cnt = hm.getOrDefault(result, 0);
            hm.put(result, cnt+1);
        }

        System.out.println(Collections.max(hm.values()));
    }
}