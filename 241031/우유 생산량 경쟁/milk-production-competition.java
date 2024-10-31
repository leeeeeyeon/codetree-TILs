import java.io.*;
import java.util.*;

public class Main {
    public static int convertToIndex(String name) {
        if (name.equals("Bessie")) return 0;
        if (name.equals("Elsie")) return 1;
        else return 2;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        List<Cow> cows = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            String[] temp = line.split(" ");

            int day = Integer.parseInt(temp[0]);
            String name = temp[1];
            int diff = Integer.parseInt(temp[2]);
            cows.add(new Cow(day, name, diff));
        }

        cows.sort((a, b) -> Integer.compare(a.day, b.day));
        
        List<Integer> info = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            info.add(7);
        }

        int answer = 0;
        String mx = "012";
        for (Cow cow : cows) {
            int idx = convertToIndex(cow.name);
            int temp = info.get(idx) + cow.diff;
            info.set(idx, temp);

            String cur = "";
            for (int i = 0; i < 3; i++) {
                if (info.get(i) == Collections.max(info)) {
                    cur += (i + "");
                }
            }

            if (!mx.equals(cur)) {
                answer++;
                mx = cur;
            }
        }

        System.out.println(answer);
    }

    public static class Cow {
        int day;
        String name;
        int diff;

        Cow(int day, String name, int diff) {
            this.day = day;
            this.name = name;
            this.diff = diff;
        }
    }
}