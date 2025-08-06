public class Troll extends Character {
    public Troll() {
        weaponBehaviour = new AxeBehavior();
    }

    @Override
    public void fight() {
        System.out.print("The troll fights with: ");
        weaponBehaviour.useWeapon();
    }
    
}
