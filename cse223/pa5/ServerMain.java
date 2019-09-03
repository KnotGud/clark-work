class ServerMain {
    public static void main(String[] args) {
       Server s = new Server();
       s.start();

       Client c = new Client("Server", "localhost");
       c.run();

       s.close();
       System.exit(0);
    }
}
