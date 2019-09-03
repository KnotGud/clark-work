/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    LocationNode is a basic node of a linked list.
 *              This class allows for read-only access of location after constructon.
 */

class LocationNode {
    private int location;
    public LocationNode next = null;

    public LocationNode() {
        location = -1;
    }

    public LocationNode(int location) {
        this.location = location;
    }

    public int location() {
        return location;
    }
}
