open ReactNative;

type reactNativeNewAppScreenColors = {. "dark": string};

[@bs.module "react-native/Libraries/NewAppScreen"]
external colors: reactNativeNewAppScreenColors = "Colors";

[@react.component]
let app = () =>
  <>
    <StatusBar barStyle=`darkContent />
    <SafeAreaView> <Galery /> </SafeAreaView>
  </>;
