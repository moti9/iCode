public class Knight extends Character {
    public Knight() {
        weaponBehaviour = new SwordBehavior();
    }

    @Override
    public void fight() {
        System.out.println("The knight fights with: ");
        weaponBehaviour.useWeapon();
    }
    
}
