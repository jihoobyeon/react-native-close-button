import CloseButton from './NativeCloseButton';
import { useEffect } from 'react';

export function useBeforeClose(toDo: () => void): void {
  useEffect(() => {
    const subscription = CloseButton.onBeforeClose(toDo);
    CloseButton.install();
    return () => subscription.remove();
  }, [toDo]);
}

export function closeNow(): void {
  return CloseButton.closeNow();
}
