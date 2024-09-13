# react-native-close-button

Module for customize behavior when close button has pressed

## Installation

```sh
yarn add react-native-close-button
```

## Usage


```js
import { closeNow, doBeforeClose } from 'react-native-close-button';

export default function App(): JSX.Element {
	doBeforeClose(async () => { // If you use doBeforeClose(), it automatically disables close button's ability to close window.
		Alert.alert('TEST', 'Test.');
		await new Promise(_ => setTimeout(_, 5000));
    closeNow(); // If you want to close app's window, you have to call closeNow().
	});
	return (
		<View />
  );
}

```


## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
