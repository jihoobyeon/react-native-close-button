# react-native-close-button

Module for customize behavior when close button has pressed

## Installation

```sh
yarn add react-native-close-button
```

## Usage


```js
import { closeNow, useBeforeClose } from 'react-native-close-button';

export default function App() {
	useBeforeClose(() => 
		Alert.alert('TEST', 'Testing RNCloseButton', [
			{ text: 'Cancel', onPress: () => {} },
			{ text: 'Close', onPress: () => closeNow() }
		]));

	return <View />;
}

```


## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
