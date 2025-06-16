from abc import ABC, abstractmethod

class Animal(ABC):
        total_animals=0

        def __init__(self,name,age,species):
                self.name=name
                self.age=age
                self.species=species
                Animal.total_animals+=1

        @abstractmethod
        def makeSound(self):
                pass
        @abstractmethod    
        def getDiet(self):
                pass
        
class Lion(Animal):
        def __init__(self, name, age, species):
                super().__init__(name, age, species)

        def makeSound(self):
            print("f{self.name} says: Roar!\n\n")
        
        def getDiet(self):
               print("f{self.name} is a carnivore")


class Elephant(Animal):
       def __init__(self, name, age, species):
            super().__init__(name, age, species)

       def makeSound(self):
              print(f"{self.name} says brumpppp")

       def getDiet(self):
              print(f"{self.name} is a herbivore")

class Parrot(Animal):
    def __init__(self, name, age):
        super().__init__(name, age, "Parrot")

    def make_sound(self):
        print(f"{self.name} says: Squawk!")

    def get_diet(self):
        print(f"{self.name} is an Omnivore.")

class Enclosure:
    totalenclosures=0

    def __init__(self,enclosureID, type):
          self.enclosureID=enclosureID
          self.type=type
          self.animals=[]
          Enclosure.totalenclosures+=1

    def add_animal(self, animal):
          if len(self.animals)<10:
                self.animals.append(animal)

    def list_animals(self):
          print(f"Enclosure {self.enclosureID} {self.type} has:")
          for animal in self.animal:
                print(f"{animal.name}")   

class Staff(ABC):
    def __init__(self, name, staffId):
        self.name = name
        self.staff_id = staffId

    @abstractmethod
    def perform_duty(self):
        print(f"{self.name} is doing general duty.")       
        
class Zookeeper(Staff):
    def perform_duty(self):
        print(f"{self.name} (Zookeeper) is feeding the animals.")

class Veterinarian(Staff):
    def perform_duty(self):
        print(f"{self.name} (Veterinarian) is checking the health of the animals.")                


class Zoo:

      def __init__(self):
            self.animals=[]
            self.enclosures=[]
            self.staff=[]

      def addAnimal(self,animals):
            if len(self.animals)<20:
                 self.animals.append(animals)


      def add_enclosure(self, enclosure):
        if len(self.enclosures) < 10:
            self.enclosures.append(enclosure)

      def add_staff(self, staff_member):
        if len(self.staff) < 10:
            self.staff.append(staff_member)

      def show_all_animals(self):
        for animal in self.animals:
            animal.make_sound()
            animal.get_diet()

      def show_staff_duties(self):
        for member in self.staff:
            member.perform_duty()

      def show_summary(self):
        print(f"\nTotal Animals: {Animal.total_animals}")
        print(f"Total Enclosures: {Enclosure.total_enclosures}")

zoooo=Zoo()

a1=Lion("abdullah", 5)
a2=Elephant("Askari", 10)
a3=Parrot("Kabeer", 2)

zoooo.addAnimal(a1)
zoooo.addAnimal(a2)
zoooo.addAnimal(a3)

e1=Enclosure(1,"Amazon")
e1.add_animal(a1)

e2 = Enclosure(2, "Rainforest")

e2.add_animal(a2)
e2.add_animal(a3)

zoooo.add_enclosure(e1)
zoooo.add_enclosure(e2)

s1=Zookeeper("Zain", 100)
s2=Veterinarian("Musdiq", 200)

zoooo.add_staff(s1)
zoooo.add_staff(s2)

print("\n--- Staff Duties ---")
zoooo.show_staff_duties()

print("\n--- Animal Sounds and Diets ---")
zoooo.show_all_animals()

print("\n--- Zoo Summary ---")
zoooo.show_summary()