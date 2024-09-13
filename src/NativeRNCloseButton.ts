import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  doBeforeClose(toDo: () => void): void;
  closeNow(): void;
}

export default TurboModuleRegistry.getEnforcing<Spec>('RNCloseButton');
