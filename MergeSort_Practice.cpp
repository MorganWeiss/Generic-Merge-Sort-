template<class T>
void merge(std::vector<T>& data, std::vector<T>& temp, int low, int middle, int high) {

	// create a temporary array ... O(N) memory complexity !!!		
	// copy the data to a temporary array 
	for (int i = low; i <= high; i++) {
		temp[i] = data[i];
	}

	int i = low;
	int j = middle + 1;
	int k = low;

	// Copy the smallest values from either the left or the right side back
	// to the original array
	while ((i <= middle) && (j <= high)) {
		if (temp[i] <= temp[j]) {
			data[k] = temp[i];
			i++;
		} 
		else {
			data[k] = temp[j];
			j++;
		}

		k++;
	}

	// Copy the rest of the left side of the array into the target array
	while (i <= middle) {
		data[k] = temp[i];
		k++;
		i++;
	}

	// Copy the rest of the right side of the array into the target array
	while (j <= high) {
		data[k] = temp[j];
		k++;
		j++;
	}
}

template<class T>
void mergesort(std::vector<T>& data, std::vector<T>& temp, int low, int high) {

	if (low >= high) {
		return;
	}

	int middle_index = (low + high) / 2;

	mergesort(data, temp, low, middle_index);
	mergesort(data, temp, middle_index + 1, high);
	merge(data, temp, low, middle_index, high);
}

template<class T>
void sort(std::vector<T>& data, std::vector<T>& temp) {
	int n = data.size();
	mergesort(data, temp, 0, n - 1);
}


int main() {
	std::vector<int> data = { 0,3,65,3,1,2,35,6 };
	int n = data.size();
	std::vector<int> temp(n, 0);

	sort(data, temp);
	print(data);

	std::cin.get();
}
