# kalman-filter
Simple Kalman filter allows to filter floating point and integer data.

## Usage

To initialize kalman filter struct use `kalman_init_*` functions. You also can initialize struct directly.

Use `kalman_*` to filter data value by value.

Use `kalman_array_*` to filter array of data.

## Example

```
kalman_filter_t filter;

// k coeficient is 0.5
// Initial value is 0
kalman_init_f(&filter, 0.5, 0);

// Add value 12 to filter
kalman_f(&filter, 12);

```
