/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    WordNode is a node of a linked list.
 *              It contains a LocationList to keep track of files given.
 *              This also provides read-access to the current count of the word.
 */

class WordNode {
    private String word;
    private int count;
    private LocationList locations;
    public WordNode next = null;

    // WordNode constructure with no args is used to build a sentinal node
    public WordNode() {
        word = "";
        locations = null;
    }

    public WordNode(String word) {
        this.word = word;
        locations = new LocationList();
    }

    public WordNode(String word, int location) {
        this.word = word;
        locations = new LocationList();

        addLocation(location);
    }

    public void addLocation(int location) {
        locations.addToEnd(location);
        count++;
    }

    public String word() {
        return word;
    }

    public String locations() {
        return locations.toString();
    }

    public int count() {
        return count;
    }
}
