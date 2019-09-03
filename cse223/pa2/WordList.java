/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    WordList is a linked list of WordNodes.
 *              This allows for basic appending of words in alphabetical order.
 *              it also provides a print method.
 */

class WordList {
    private WordNode sentinal;

    public WordList() {
        sentinal = new WordNode();
    }

    public void addWord(String word, int location) {
        WordNode p = sentinal;
        WordNode c = sentinal.next;
        while (c != null) {
            // check returns a positive number if the current node's word is alphabetically after the given word.
            // check returns 0 if the word matches exactly.
            int check = c.word().compareTo(word);
            if (check > 0) {
                p.next = new WordNode(word, location);
                p.next.next = c;
                return;
            } else if (check == 0) {
                c.addLocation(location);
                return;
            }
            p = c;
            c = c.next;
        }
        p.next = new WordNode(word, location);
    }

    public void print() {
        WordNode c = sentinal.next;
        while (c != null) {
            System.out.println(c.word() + " " + c.locations());
            c = c.next;
        }
    }
}
