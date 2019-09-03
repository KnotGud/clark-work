/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    IndexUtility is an object that will read from stdin and build a word list
 *              of words and indexes sorted in alphabetical order
 */

import java.util.Scanner;

class IndexUtility {
    public IndexUtility() {
    }

    public WordList buildIndex() {
        WordList wl = new WordList();
        int count = 0;
        Scanner s = new Scanner(System.in);

        while (s.hasNext()) {
            String in = cleanString(s.next());
            count++; // this logic allows for the count to be accurate, and also have location be >1
            wl.addWord(in, count);
        }
        s.close();
        return wl;
    }

    private String cleanString(String in) {
        String ret = "";
        for (int i = 0; i < in.length(); i++) {
            char c = in.charAt(i);
            if (Character.isLetter(c)) {
                ret += Character.toLowerCase(c);
            }
        } 
        return ret;
    }
}
