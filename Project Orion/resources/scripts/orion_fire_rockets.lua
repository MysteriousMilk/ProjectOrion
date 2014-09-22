-- Weapon Types:
-- 1 = Rockets and Missiles
-- 2 = Lasers
-- 3 = Rail Guns

player = GetPlayer();

enemy = GetEnemy();
x = enemy:GetX();
y = enemy:GetY();

weaponType = 1;

for i=0,7,1 do
	player:FireProjectileWithDelay(1, x, y, i*0.2);
end