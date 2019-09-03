/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    Main is the starting point of the game app.
 *              Main is responsible for validating Cli Args and starting the game.
 */
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        GTree game;
        switch (args.length) {
            case 0:
                game = new GTree();
                break;
            case 1:
                game = new GTree(args[0]);
                break;
            default:
                printUsage();
                return;
        }

        Scanner s = new Scanner(System.in);
        try {
            // this is a quick and dirty way of implementing a play again feature
            while (game.Play(s)) {};
        } catch (Exception e) {
            System.out.println("Error in loading db: " + e.getMessage());
            e.printStackTrace();
        } finally {
            s.close();
        }
    }

    private static void printUsage() {
        System.out.println("Usage: java Main [path to db file]");
        System.out.println("Path to db file is optional (Default: 'db')");
    }
}
