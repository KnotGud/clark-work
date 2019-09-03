import java.net.Socket;
import java.util.Scanner;
import java.io.PrintWriter;

class Client {
    private String username;
    private String address;
    public static final String exitSignal = "exit";
    public static final String messageFormat = "|%s| %s\n";

    public Client(String username, String address) {
        this.username = username;
        this.address = address;
    }

    public void run() {
        try {
            Socket conn = new Socket(address, Server.port);
            ClientWorker worker = new ClientWorker(conn);
            worker.start();

            PrintWriter w = new PrintWriter(conn.getOutputStream());

            w.printf("%s connected\n", username);
            w.flush();
            Scanner s = new Scanner(System.in);
            while (s.hasNextLine() && conn.getInetAddress().isReachable(4)) {
                String in = s.nextLine();
                if (in.equals(exitSignal)) {
                    w.printf("%s disconnected\n", username);
                    w.flush();
                    break;
                }
                w.printf(messageFormat, username, in);
                w.flush();
            }
            w.close();
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        } 
    }
}
