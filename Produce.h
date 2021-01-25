#pragma once
#include "DLR.h"

template <typename Key, typename Info>
DLR<Key, Info> produce(const DLR<Key, Info> &r1, int start1, int steps1, bool dir1,
						const DLR<Key, Info> &r2, int start2, int steps2, bool dir2,
						int num, bool dir_out)
{

	DLR<Key, Info> product;

	if (num <= 0) {
		return product;
	}

	typename DLR<Key, Info>::Iterator it1 = r1.begin();
 	typename DLR<Key, Info>::Iterator it2 = r2.begin();

	it1 = (dir1 ? it1 + start1 : it1 - start1);
	it2 = (dir2 ? it2 + start2 : it2 - start2);

	while (num > 0) {
		
		for (int i = 0; i < steps1; i++) {
			dir_out ? product.pushNext(it1.getKey(), it1.getInfo()) : product.pushPrev(it1.getKey(), it1.getInfo());
			dir1 ? it1++ : it1--;
		}

		for (int i = 0; i < steps2; i++) {
			dir_out ? product.pushNext(it2.getKey(), it2.getInfo()) : product.pushPrev(it2.getKey(),it2.getInfo());
			dir2 ? it2++ : it2--;
		}

		num--;
	}
	
	return product;
}
