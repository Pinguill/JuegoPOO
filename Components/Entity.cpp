class Entity
{
private:
   /* data */
public:
   Entity(/* args */);
   ~Entity();
   // Functions
   virtual void createSprite() = 0;
};

Entity::Entity(/* args */)
{
}

Entity::~Entity()
{
}


class weapon : public Entity
{
private:
   /* data */
public:
   weapon(/* args */);
   ~weapon();

   //Functions
   void createSprite();
};

weapon::weapon(/* args */)
{
}

weapon::~weapon()
{
}

class potion :public Entity
{
private:
   /* data */
public:
   potion(/* args */);
   ~potion();

   //Functions
   void createSprite();
};

potion::potion(/* args */)
{
}

potion::~potion()
{
}

class dungueonBox : public Entity
{
private:
   /* data */
public:
   dungueonBox(/* args */);
   ~dungueonBox();

   //Functions
   void createSprite();
};

dungueonBox::dungueonBox(/* args */)
{
}

dungueonBox::~dungueonBox()
{
}

class herz : public Entity
{
private:
   /* data */
public:
   herz(/* args */);
   ~herz();
   
   //Functions
   void createSprite();
};

herz::herz(/* args */)
{
}

herz::~herz()
{
}
