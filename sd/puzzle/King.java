public class King extends Character {
    public King() {
        weaponBehaviour = new SwordBehavior();
    }

    @Override
    public void fight() {
        System.out.print("The king fights with: ");
        weaponBehaviour.useWeapon();
    }

    public void useNewWeapon(WeaponBehavior newWeapon) {
        setWeapon(newWeapon);
        System.out.print("The king has changed weapon to: ");
        weaponBehaviour.useWeapon();
    }

}

