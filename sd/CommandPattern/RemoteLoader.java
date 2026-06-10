public class RemoteLoader {

    public static void main(String[] args) {
        RemoteControl remoteControl = new RemoteControl();

        Light livingRoomLight = new Light("Living Room Light");
        Light kitchenLight = new Light("Kitchen Light");
        CeillingFan ceillingFan = new CeillingFan("Ceiling Fan");
        GarageDoor garageDoor = new GarageDoor();
        Stereo stereo = new Stereo();

        LightOnCommand livingRoomLightOn = new LightOnCommand(livingRoomLight);
        LightOffCommand lvingRoomLightOff = new LightOffCommand(livingRoomLight);

        LightOnCommand kitchenRommLightOn = new LightOnCommand(kitchenLight);
        LightOffCommand kitchenroomLightOff = new LightOffCommand(kitchenLight);

        CeillingFanHighCommand ceillingFanOn = new CeillingFanHighCommand(ceillingFan);
        CeillingFanOffCommand ceillingFanOff = new CeillingFanOffCommand(ceillingFan);

        GarageDoorUpCommand garageDoorUp = new GarageDoorUpCommand(garageDoor);
        GarageDoorDownCommand garageDoorDown = new GarageDoorDownCommand(garageDoor);

        StereoOnWithCDCommand stereoOnWithCD = new StereoOnWithCDCommand(stereo);
        StereoOffCommand stereoOff = new StereoOffCommand(stereo);

        
        remoteControl.setCommand(0, livingRoomLightOn, lvingRoomLightOff);
        remoteControl.setCommand(1, kitchenRommLightOn, kitchenroomLightOff);
        remoteControl.setCommand(2, ceillingFanOn, ceillingFanOff);
        remoteControl.setCommand(3, garageDoorUp, garageDoorDown);
        remoteControl.setCommand(4, stereoOnWithCD, stereoOff);

        System.out.println(remoteControl);
        
        remoteControl.onButtonWasPushed(0);
        remoteControl.offButtonWasPushed(0);

        // remoteControl.onButtonWasPushed(1);
        // remoteControl.offButtonWasPushed(1);

        // remoteControl.onButtonWasPushed(2);
        // remoteControl.offButtonWasPushed(2);

        // remoteControl.onButtonWasPushed(3);
        // remoteControl.offButtonWasPushed(3);

        // remoteControl.onButtonWasPushed(4);
        // remoteControl.offButtonWasPushed(4);

        
        System.out.println(remoteControl);

        remoteControl.undoButtonWasPushed();
        remoteControl.offButtonWasPushed(0);
        remoteControl.onButtonWasPushed(0);

        System.out.println(remoteControl);
        remoteControl.undoButtonWasPushed();
    }






    
}
