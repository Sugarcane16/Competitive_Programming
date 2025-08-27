def start():
    print("\n🌊 Scene 1: The Pond")
    print("You hatch among bright yellow ducklings. But your feathers are gray, your neck too long.")
    print("The other ducklings snicker: \"What an ugly thing!\"")
    print("\nChoices:")
    print("1. Swim away to be alone.")
    print("2. Confront them and demand respect.")
    print("3. Stay silent and endure the mocking.")
    choice = input("> ")

    if choice == "1":
        forest_path()
    elif choice == "2":
        confrontation()
    elif choice == "3":
        silent_path()
    else:
        print("You panic and dive underwater. ENDING: Lost in the Pond.")

def forest_path():
    print("\n🌲 Scene 2: The Forest")
    print("You wander into the forest. It’s dark, damp, but quiet. No laughter here.")
    print("A squirrel drops an acorn on your head. It chitters: \"Strange bird, why are you alone?\"")
    print("\nChoices:")
    print("a. Ask the squirrel for advice.")
    print("b. Keep walking deeper into the forest.")
    print("c. Return to the pond, even if it hurts.")
    choice = input("> ")

    if choice == "a":
        print("The squirrel shrugs. \"Winter is coming. Find shelter, or you’ll freeze.\"")
        winter_path()
    elif choice == "b":
        print("The forest grows colder. You feel eyes watching you...")
        winter_path()
    elif choice == "c":
        start()  # loop back
    else:
        print("You curl up under a tree, falling asleep. Hunters find you. ENDING: Caught in the Forest.")

def confrontation():
    print("\n🔥 Scene 2: Confrontation at the Pond")
    print("You flap your wings and shout: \"Stop it!\"")
    print("The ducklings fall silent, then smirk. \"Prove you’re not weak,\" they jeer.")
    print("\nChoices:")
    print("a. Challenge them to a race.")
    print("b. Attack the ringleader.")
    print("c. Leave with dignity.")
    choice = input("> ")

    if choice == "a":
        outcome = input("Do you win the race? (y/n) > ")
        if outcome == "y":
            print("🏆 You outswim them all. They cheer. You feel accepted… for now.")
            winter_path()
        else:
            print("You fall behind. They laugh louder. ENDING: Outcast.")
    elif choice == "b":
        print("You lunge! The ringleader flees. The others scatter.")
        print("But your heart aches. Violence doesn’t heal loneliness.")
        winter_path()
    elif choice == "c":
        print("You turn your back and walk away with quiet dignity.")
        discovery_path()
    else:
        print("You freeze. They lose interest. ENDING: Forgotten.")

def silent_path():
    print("\n🤐 Scene 2: Silent Endurance")
    print("You lower your head. The laughter grows sharper.")
    print("But one duckling glances at you with pity.")
    print("\nChoices:")
    print("a. Accept their quiet friendship.")
    print("b. Reject it and swim away alone.")
    choice = input("> ")

    if choice == "a":
        print("The two of you leave together. Not alone anymore.")
        winter_path()
    else:
        forest_path()

def winter_path():
    print("\n❄️ Scene 3: Winter")
    print("Snow falls. Ice forms. You grow thinner each day.")
    print("Cold bites at your feathers. The world feels endless.")
    print("\nChoices:")
    print("a. Seek shelter with humans.")
    print("b. Hide in the reeds and wait.")
    print("c. Wander south in search of warmth.")
    choice = input("> ")

    if choice == "a":
        barnyard_path()
    elif choice == "b":
        print("You curl up in the reeds, shivering. Time passes slowly…")
        spring_transformation()
    elif choice == "c":
        print("You follow the geese south, wings aching. Many fall, but you survive.")
        spring_transformation()
    else:
        print("The cold is too much. ENDING: Frozen Pond.")

def barnyard_path():
    print("\n🏚 Scene 3: Barnyard")
    print("You stumble into a farm. Chickens cluck, dogs bark, children stare.")
    print("A farmer approaches. His eyes soften.")
    print("\nChoices:")
    print("a. Stay with the farmer, hoping for kindness.")
    print("b. Flee before you are caged.")
    choice = input("> ")

    if choice == "a":
        print("The farmer feeds you scraps, shelters you from the cold.")
        print("But you never feel truly free.")
        print("ENDING: Adopted Pet.")
    else:
        print("You flap wildly, escape into the night. The stars guide you.")
        spring_transformation()

def discovery_path():
    print("\n🌌 Scene 3: Discovery")
    print("You leave the pond and wander across meadows and streams.")
    print("You see flocks of geese flying high, a frog singing in the swamp, humans by a barn.")
    print("\nChoices:")
    print("a. Fly with the geese.")
    print("b. Sit with the frog and listen to wisdom.")
    print("c. Approach the humans.")
    choice = input("> ")

    if choice == "a":
        print("You soar with them, heart pounding. Freedom tastes sharp and sweet.")
        spring_transformation()
    elif choice == "b":
        print('"Life is hard, but you are harder," the frog croaks.')
        print("You learn patience through stillness.")
        spring_transformation()
    elif choice == "c":
        barnyard_path()
    else:
        print("You wander without end. ENDING: Eternal Wanderer.")

def spring_transformation():
    print("\n🌸 Scene 4: Spring")
    print("The ice melts. You feel stronger, wings stretching wide.")
    print("You see swans on the water, elegant and shining.")
    print("You bow your head to the water… and see your reflection.")
    print("Not gray, not ugly—white feathers, long neck, graceful wings.")
    print("\nENDING: True Swan 🦢")
    print("But remember: the path you took shaped the swan you became.")
    print("Different choices, different you.")
    print("~ THE END ~")

# Run the game
start()
