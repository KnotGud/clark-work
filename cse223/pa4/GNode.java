/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    GNode is the Game Node of a binary tree.
 *              It is used to store game and question data.
 */
import java.util.Scanner;
import java.io.PrintWriter;

class GNode {
    private String text;
    private boolean isQuestion;
    public GNode Left = null;
    public GNode Right = null;

    public GNode(String text, boolean isQuestion) {
        this.text = text;
        this.isQuestion = isQuestion;
    }

    public String Text() {
        return text;
    }

    public boolean IsQuestion() {
        return isQuestion;
    }

    public static GNode Load(Scanner s) {
        boolean isQ = s.nextLine().equals("Q:");
        String t = s.nextLine();

        GNode temp = new GNode(t, isQ);
        if (isQ) {
            temp.Left = GNode.Load(s);
            temp.Right = GNode.Load(s);
        }
        return temp;
    }

    public void Save(PrintWriter w) {
        if (isQuestion) {
            w.println("Q:");
            w.println(text);
            Left.Save(w);
            Right.Save(w);
        } else {
            w.println("A:");
            w.println(text);
        }
    }
}
