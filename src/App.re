open ReactNative;

type reactNativeNewAppScreenColors = {
  .
  "primary": string,
  "white": string,
  "lighter": string,
  "light": string,
  "black": string,
  "dark": string,
};

[@bs.module "react-native/Libraries/NewAppScreen"]
external colors: reactNativeNewAppScreenColors = "Colors";

let styles =
  Style.(
    StyleSheet.create({
      "scrollView": style(~backgroundColor=colors##lighter, ()),
      "engine": style(~position=`absolute, ~right=0.->dp, ()),
      "body": style(~backgroundColor=colors##white, ()),
      "sectionContainer":
        style(~marginTop=32.->dp, ~paddingHorizontal=24.->dp, ()),
      "sectionTitle":
        style(~fontSize=24., ~fontWeight=`_600, ~color=colors##black, ()),
      "sectionDescription":
        style(
          ~marginTop=8.->dp,
          ~fontSize=18.,
          ~fontWeight=`_400,
          ~color=colors##dark,
          (),
        ),
      "highlight": style(~fontWeight=`_700, ()),
      "footer":
        style(
          ~color=colors##dark,
          ~fontSize=12.,
          ~fontWeight=`_600,
          ~padding=4.->dp,
          ~paddingRight=12.->dp,
          ~textAlign=`right,
          (),
        ),
    })
  );

[@react.component]
let app = () =>
  <>
    <StatusBar barStyle=`darkContent />
    <SafeAreaView>
      <ScrollView
        contentInsetAdjustmentBehavior=`automatic style={styles##scrollView}>
        <View style={styles##body}>
          <Galery/>
        </View>
      </ScrollView>
    </SafeAreaView>
  </>;
