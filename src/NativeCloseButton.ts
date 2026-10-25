import { TurboModuleRegistry, type CodegenTypes, type TurboModule } from 'react-native';

export interface Spec extends TurboModule {
  readonly onBeforeClose: CodegenTypes.EventEmitter<void>;
  install(): void;
  closeNow(): void;
}

export default TurboModuleRegistry.getEnforcing<Spec>('CloseButton');