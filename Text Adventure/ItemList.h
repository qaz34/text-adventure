#pragma once
#include "Inventory\Items.h"
#include "Inventory\Weapon.h"
#include "Inventory\Armor.h"
class ItemList
{
public:
	Item* weapons[7];
	Item* Helmets[7];
	Item* Chest[7];
	Item* Arms[7];
	Item* Legs[7];
	Item* Feet[7];
	ItemList(int level) {

		weapons[0] = new Weapon("Fire Sword", weaponType::MELEE, ElementalDamage::FIRE, (int)pow(level, 1.5) * level / 1.25);
		weapons[1] = new Weapon("Earth Fists", weaponType::MELEE, ElementalDamage::EARTH, (int)pow(level, 2.3));
		weapons[2] = new Weapon("Sword of Jeffry", weaponType::MELEE, ElementalDamage::WIND, (int)pow(level, 2.7) - 2);
		weapons[3] = new Weapon("Handgun of Water", weaponType::RANGED, ElementalDamage::WATER, level * 3);
		weapons[4] = new Weapon("Wand of Mistical Fire", weaponType::MAGIC, ElementalDamage::FIRE, (int)pow(level, 2));
		weapons[5] = new Weapon("Power Sword", weaponType::MELEE, ElementalDamage::PHYSICAL, (int)pow(level, 3));
		weapons[6] = new Weapon("Red Queen", weaponType::MELEE, ElementalDamage::FIRE, (int)pow(level, 3.1));

		Helmets[0] = new Armor("Knight Helmet", armorType::HEAD, { (int)pow(level, 1.6),{ ElementalDamage::PHYSICAL, ElementalDamage::EARTH } });
		Helmets[1] = new Armor("Flame Retardant Helmet", armorType::HEAD, { (int)pow((float)level, (float)1.3),{ ElementalDamage::FIRE, ElementalDamage::WIND} });
		Helmets[2] = new Armor("Balaclava", armorType::HEAD, { (int)pow((float)level, (float)1.2),{ ElementalDamage::EARTH, ElementalDamage::WATER, ElementalDamage::WIND } });
		Helmets[3] = new Armor("Snapback", armorType::HEAD, { (int)pow(level, 2),{/*None*/} });
		Helmets[4] = new Armor("Pirate Hat", armorType::HEAD, { (int)pow(level, 1.3),{ ElementalDamage::WATER } });
		Helmets[5] = new Armor("Samurai Helmet", armorType::HEAD, { (int)pow(level, 1.4),{ ElementalDamage::PHYSICAL, ElementalDamage::FIRE } });
		Helmets[6] = new Armor("Helmet of Jeffry", armorType::HEAD, { (int)pow(level, 1.1),{ ElementalDamage::FIRE, ElementalDamage::EARTH, ElementalDamage::PHYSICAL, ElementalDamage::WATER, ElementalDamage::WIND } });

		Chest[0] = new Armor("Fireproof Clothing", armorType::CHEST, { (int)pow(level, 1.7),{ ElementalDamage::FIRE } });
		Chest[1] = new Armor("Knight Chest", armorType::CHEST, { (int)pow(level, 2.0),{ ElementalDamage::FIRE, ElementalDamage::PHYSICAL } });
		Chest[2] = new Armor("Titanium Tunic", armorType::CHEST, { (int)pow(level, 2.1),{ ElementalDamage::FIRE, ElementalDamage::EARTH } });
		Chest[3] = new Armor("Cuirass of Hope", armorType::CHEST, { (int)pow(level, 1.9),{ ElementalDamage::WATER, ElementalDamage::EARTH } });
		Chest[4] = new Armor("Reactive Chainmail", armorType::CHEST, { (int)pow(level, 2.0),{ ElementalDamage::PHYSICAL, ElementalDamage::WIND } });
		Chest[5] = new Armor("Scale Mail", armorType::CHEST, { (int)pow(level, 2.1),{ ElementalDamage::WIND, ElementalDamage::FIRE } });
		Chest[6] = new Armor("Carapace of Jeffry", armorType::CHEST, { (int)pow(level, 2),{ ElementalDamage::FIRE, ElementalDamage::EARTH, ElementalDamage::PHYSICAL, ElementalDamage::WATER, ElementalDamage::WIND } });

		Arms[0] = new Armor("Vambraces of Power", armorType::ARMS, { (int)pow(level, 1.5),{ ElementalDamage::PHYSICAL, ElementalDamage::EARTH } });
		Arms[1] = new Armor("Powerful Gauntlet", armorType::ARMS, { (int)pow(level, 1.8),{ ElementalDamage::FIRE, ElementalDamage::WATER } });
		Arms[2] = new Armor("Cloth Bracer", armorType::ARMS, { (int)pow(level, 1.3),{  ElementalDamage::WATER, ElementalDamage::WIND } });
		Arms[3] = new Armor("Armguard of Jeffry", armorType::ARMS, { (int)pow(level, 1.5),{ ElementalDamage::FIRE, ElementalDamage::EARTH, ElementalDamage::PHYSICAL, ElementalDamage::WATER, ElementalDamage::WIND } });
		Arms[4] = new Armor("Hobo Gloves", armorType::ARMS, { (int)pow(level, 1.9),{ } });
		Arms[5] = new Armor("Shinny New Watch", armorType::ARMS, { (int)pow(level, 1.2),{ ElementalDamage::FIRE, ElementalDamage::WATER, ElementalDamage::WIND } });
		Arms[6] = new Armor("Gauntlet of Peace", armorType::ARMS, { (int)pow(level, 1.7),{  ElementalDamage::PHYSICAL, ElementalDamage::EARTH } });

		Legs[0] = new Armor("Leggings of Jeffry", armorType::LEGS, { (int)pow(level, 1.8),{ ElementalDamage::FIRE, ElementalDamage::EARTH, ElementalDamage::PHYSICAL, ElementalDamage::WATER, ElementalDamage::WIND } });
		Legs[1] = new Armor("Irish Kilt", armorType::LEGS, { (int)pow(level, 1.5),{ ElementalDamage::FIRE, ElementalDamage::WATER } });
		Legs[2] = new Armor("Steel Pants", armorType::LEGS, { (int)pow(level, 1.8),{ ElementalDamage::FIRE, ElementalDamage::PHYSICAL } });
		Legs[3] = new Armor("Leather Legguards", armorType::LEGS, { (int)pow(level, 1.4),{ ElementalDamage::PHYSICAL, ElementalDamage::WATER } });
		Legs[4] = new Armor("Super Greaves", armorType::LEGS, { (int)pow(level, 1.6),{ ElementalDamage::WIND, ElementalDamage::WATER } });
		Legs[5] = new Armor("Pants of Power", armorType::LEGS, { (int)pow(level, 2),{ ElementalDamage::PHYSICAL, ElementalDamage::EARTH } });
		Legs[6] = new Armor("Cargo Pants", armorType::LEGS, { (int)pow(level, 1.5),{ ElementalDamage::EARTH, ElementalDamage::PHYSICAL } });

		Feet[0] = new Armor("Boots of Jeffry", armorType::FEET, { (int)pow(level, 1.7),{ ElementalDamage::FIRE, ElementalDamage::EARTH, ElementalDamage::PHYSICAL, ElementalDamage::WATER, ElementalDamage::WIND } });
		Feet[1] = new Armor("Good ol' Stompers", armorType::FEET, { (int)pow(level, 1.5),{ ElementalDamage::EARTH, ElementalDamage::WATER } });
		Feet[2] = new Armor("Slippery Sandals", armorType::FEET, { (int)pow(level, 1.6),{ ElementalDamage::FIRE, ElementalDamage::WATER } });
		Feet[3] = new Armor("Hobbit Footguards", armorType::FEET, { (int)pow(level, 1.9),{ ElementalDamage::WATER, ElementalDamage::WIND } });
		Feet[4] = new Armor("Chainmail Warboots", armorType::FEET, { (int)pow(level, 2),{ ElementalDamage::FIRE, ElementalDamage::PHYSICAL } });
		Feet[5] = new Armor("Running Sneekers", armorType::FEET, { (int)pow(level, 1.5),{ ElementalDamage::FIRE, ElementalDamage::WIND, ElementalDamage::EARTH } });
		Feet[6] = new Armor("Reactive Boots", armorType::FEET, { (int)pow(level, 2.1),{ ElementalDamage::PHYSICAL } });
		
	}
	~ItemList() {
		for (int i = 0; i < 7; ++i) {
			delete weapons[i];
			delete Helmets[i];
			delete Chest[i];
			delete Arms[i];
			delete Legs[i];
			delete Feet[i];
		}
	}
	Item* getItem(int type, int index) {
		switch (type)
		{
		case 0:
			return Helmets[index];
		case 1:
			return Chest[index];
		case 2:
			return Arms[index];
		case 3:
			return Legs[index];
		case 4:
			return Feet[index];
		case 5:
			return weapons[index];
		default:
			break;
		}
	}
};

