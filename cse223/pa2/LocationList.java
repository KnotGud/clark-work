/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    LocationList is a linked list of LocationNode objects.
 *              This allows basic appending to the list as well as a toStirng.
 */

class LocationList {
    private LocationNode sentinal;

    public LocationList() {
        sentinal = new LocationNode();
    }

    public void addToEnd(int data) {
        LocationNode c = sentinal;
        while (c.next != null) {
            c = c.next;
        }
        c.next = new LocationNode(data);
    }

    public String toString() {
        String ret = "";
        LocationNode c = sentinal.next;
        while (c != null) {
            ret += c.location();
            // this logic is to add commas to separate
            if (c.next != null) {
                ret += ",";
            }
            c = c.next;
        }

        return ret;
    }
}
