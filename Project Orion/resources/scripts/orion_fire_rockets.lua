-- Weapon Types:
-- 1 = Rockets and Missiles
-- 2 = Lasers
-- 3 = Rail Guns

player = GetPlayer();
weaponType = 1;

for i=0,2,1 do
	player:FireProjectileWithDelay(1, i*0.4);
end