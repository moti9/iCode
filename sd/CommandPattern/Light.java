public class Light {

    String name;

    public Light(String name) {
        this.name = name;
    }

    public void on() {
        System.out.println(this.name + " - ON");
    }
    
    public void off() {
        System.out.println(this.name + " - OFF");
    }
}
