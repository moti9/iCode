public class RemoteControlTest {
    public static void main(String[] args) {
        // Initiate a remote
        SimpleRemoteControl remote = new SimpleRemoteControl();
        // Receiver of request
        Light light = new Light("Living Room Light");
        GarageDoor garageDoor = new GarageDoor();
        // Command
        LightOnCommand lightOn = new LightOnCommand(light);
        GarageDoorUpCommand garageOpen = new GarageDoorUpCommand(garageDoor);
    
        // Set command to invoker
        remote.setCommand(lightOn);
        remote.buttonWasPresed();

        remote.setCommand(garageOpen);
        remote.buttonWasPresed();

    }
}
