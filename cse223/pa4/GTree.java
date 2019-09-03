/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    GTree is a Game Tree which utilizes GNodes to make a
 *              binary tree of questions and answers.
 */
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;

class GTree {
    private GNode root = null;
    private String dbPath = "db";

    public GTree() {}

    public GTree(String dbPath) {
        this.dbPath = dbPath;
    }

    private void  load() throws Exception {
        Scanner s;
        try {
           s = new Scanner(new File(dbPath));
        } catch (FileNotFoundException e) {
            throw new Exception("DB file not found: " + dbPath);
        }
        root = GNode.Load(s);
        s.close();
    }

    private void save() throws Exception {
        PrintWriter w;
        try {
            w = new PrintWriter(new File(dbPath));
        } catch (FileNotFoundException e) {
            throw new Exception("DB file not found: " + dbPath);
        }

        root.Save(w);
        w.close();
    }

    // Play runs the Game by traversing the GTree.
    // Play takes a scanner of the user input and ueses it to play the game.
    // This will throw an Exception if the db file is unable to be loaded
    // this will return true if the user wants to play again.
    public boolean Play(Scanner s) throws Exception {
        load();

        GNode prev = null;
        boolean prevDirection = true; // this is used to indicate whether left or right subnode is temp (used in reordering of tree)
        GNode temp = root;
        while (temp != null) {
            if (temp.IsQuestion()) {
                prev = temp;
                System.out.println(temp.Text() + "?");
                prevDirection = readUserAnswer(s);
                temp = prevDirection ? temp.Left : temp.Right;
            } else {
                System.out.println("Is the object a " + temp.Text());
                // This code block runs if the answer was not gueessed
                if (!readUserAnswer(s)) {
                    System.out.println("Ok, I don't know what object you're thinking of.");
                    System.out.println("What object were you thinking of?");
                    GNode newA = new GNode(s.nextLine(), false);

                    System.out.println(
                        "What is a question for which a 'yes' answer means a " + newA.Text() +
                        " and a 'no' answer means a " +  temp.Text() + "?"
                    );
                    GNode newQ = new GNode(s.nextLine(), true);
                    newQ.Left = newA;
                    newQ.Right = temp;
                    if (prev == null) { // this covers the case that the Answer is the root node
                        root = newQ;
                    } else if (prevDirection) { // this covers the case that the answer is left to the prev question
                        prev.Left = newQ;
                    } else { // this covers the case that the answer is right of the prev question
                        prev.Right = newQ;
                    }

                    save();
                }
                break;
            }
        }
        // This section is a quick and dirty way to implement "play again" functionality
        System.out.println("Play again?");
        return readUserAnswer(s);
    }

    private boolean readUserAnswer(Scanner s) {
        while (true) {
            String in = s.nextLine();
            if (in.equals("y")) {
                return true;
            } else if (in.equals("n")) {
                return false;
            } else {
                System.out.println("Invalid Answer! (Either y or n)");
            }
        }
    }
}
