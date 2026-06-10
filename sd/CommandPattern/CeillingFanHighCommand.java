public class CeillingFanHighCommand implements Command {
    CeillingFan ceillingFan;
    int prevSpeed;

    public CeillingFanHighCommand(CeillingFan ceillingFan) {
        this.ceillingFan = ceillingFan;
    }

    @Override
    public void execute() {
        this.prevSpeed = this.ceillingFan.getSpeed();
        this.ceillingFan.high();

    }

    @Override
    public void undo() {
        if (this.prevSpeed == CeillingFan.HIGH) {
            this.ceillingFan.high();
        } else if (this.prevSpeed == CeillingFan.MEDIUM) {
            this.ceillingFan.medium();
        } else if (this.prevSpeed == CeillingFan.LOW) {
            this.ceillingFan.low();
        } else if (this.prevSpeed == CeillingFan.OFF) {
            this.ceillingFan.off();
        }
    }

}
