#ifndef _WEAPONFACTORY_HPP_
#define _WEAPONFACTORY_HPP_

#include <stdio.h>
#include "..\..\CppSQLite\CppSQLite3.h"
#include "..\Game\Weapon.hpp"

using namespace std;
using namespace Orion::Game;

namespace Orion
{
	namespace Factories
	{

		class WeaponFactory
		{
		public:
			WeaponFactory()
			{

			}

			shared_ptr<Weapon> GetWeaponById(int id)
			{
				shared_ptr<Weapon> weapon = nullptr;

				try
				{
					mDatabase.open("database/oriondb.s3db");

					char sql[255];
					sprintf(sql, "SELECT WpnId, WpnName, WpnMinLvl FROM Weapon WHERE WpnId = %d", id);

					CppSQLite3Query query = mDatabase.execQuery(sql);
					while (!query.eof())
					{
						weapon = make_shared<Weapon>(query.getIntField(0),
							query.fieldValue(1),
							query.getIntField(2));
						break;
					}

					if (weapon != nullptr)
					{
						sprintf(sql, "SELECT * FROM Projectile WHERE WpnId = %d", id);

						query = mDatabase.execQuery(sql);
						while (!query.eof())
						{
							switch (weapon->GetId())
							{
								case WEAPON_TYPE_ROCKET:
									weapon->SetProjectile(make_shared<RocketProjectile>(query.getIntField(0),
										query.fieldValue(1),
										query.fieldValue(2),
										query.fieldValue(3),
										query.getIntField(4),
										query.getFloatField(5)));
									break;
								default:
									weapon->SetProjectile(make_shared<Projectile>(query.getIntField(0),
										query.fieldValue(1),
										query.fieldValue(2),
										query.fieldValue(3),
										query.getIntField(4),
										query.getFloatField(5)));
									break;
							}
							break;
						}
					}
				}
				catch (CppSQLite3Exception e)
				{
					printf("%d:%s\n", e.errorCode(), e.errorMessage());
				}

				return weapon;
			}

		private:
			CppSQLite3DB mDatabase;
		};
	}
}

#endif //_WEAPONFACTORY_HPP_