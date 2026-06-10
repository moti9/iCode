public class CeillingFanOffCommand implements Command {
    CeillingFan ceillingFan;
    
    public CeillingFanOffCommand(CeillingFan ceillingFan) {
        this.ceillingFan = ceillingFan;
    }

    @Override
    public void execute() {
        this.ceillingFan.off();
    }

    @Override
    public void undo() {
        this.ceillingFan.high();
    }
}
