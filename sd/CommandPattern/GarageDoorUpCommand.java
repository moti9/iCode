public class GarageDoorUpCommand implements Command {
    GarageDoor door;

    public GarageDoorUpCommand(GarageDoor garageDoor) {
        door = garageDoor;
    }

    @Override
    public void execute() {
        door.up();

    }

    @Override
    public void undo() {
        this.door.down();
    }
}
