import java.util.Scanner;
class ClientMain {
    public static void main(String[] args) {
        String username;
        String server = "localhost";

        switch (args.length) {
            case 2:
                server = args[1];
            case 1:
                username = args[0];
                break;
            default:
                printUsage();
                return;
        }
        Client c = new Client(username, server);
        c.run();
    }

    static void printUsage() {
        System.out.println("Usage: Java ClientMain [Username] [Server]\n\tUsername\tusername to sign in as.\n\tServer  \tserver address to connect to. (default: localhost)");
    }
}


