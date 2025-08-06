public class Queen extends Character {
    public Queen() {
        weaponBehaviour = new KnifeBehavior();
    }

    @Override
    public void fight() {
        System.out.println("The queen fights with: ");
        weaponBehaviour.useWeapon();
    }
    
}
