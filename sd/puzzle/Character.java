abstract class Character {
    WeaponBehavior weaponBehaviour;

    public void fight() {
        if (weaponBehaviour != null) {
            weaponBehaviour.useWeapon();
        } else {
            System.out.println("No weapon to fight with.");
        }
    }

    public void setWeapon(WeaponBehavior weaponBehaviour) {
        this.weaponBehaviour = weaponBehaviour;
    }
}