import { Navigation } from "react-native-navigation";
import App from "./App";

Navigation.registerComponent("navigation.Gallery", () => App);

Navigation.events().registerAppLaunchedListener(() =>
  Navigation.setRoot({
    root: {
      bottomTabs: {
        children: [
          {
            component: {
              name: "navigation.Gallery",
              options: {
                bottomTab: {
                  text: "Main"
                }
              }
            }
          }
        ]
      }
    }
  })
);
