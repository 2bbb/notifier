# notifier

notify when value will/did change.

## How to use

```
bbb::notifier<int> x;
bbb::notifier<std::string> str;

...

x.value_will_change([](int from) { /* DO SOMETHING */ });
x.value_did_change([](int to) { /* DO SOMETHING */ });

str.value_will_change([](const std::string &from) { /* DO SOMETHING */ });
str.value_did_change([](const std::string &to) { /* DO SOMETHING */ });

str = "ABC";
str += "DEF";
str[0] = "C";
```

## Type

### Arithmetic type

`int`, `unsigned char`, `float`, etc...

### std::basic_string<char_type>

`std::string`, `std::wstring`, etc...

## API

### void value_will_change(std::<void(T)>)
### void value_did_change(std::<void(T)>)

T == arithmetic type

### void value_will_change(std::<void(const T &)>)
### void value_did_change(std::<void(const T &)>)

T == basic_string<char_type>

