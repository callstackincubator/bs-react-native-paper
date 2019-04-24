open BsReactNative;
open Navigation;
open BsReactNativePaper;
open Paper;

module Styles = {
  open Style;

  let container = style([flex(1.0)]);

  let fab =
    style([
      alignSelf(Center),
      position(Absolute),
      bottom(Pt(0.)),
      margin(Pt(16.)),
    ]);

  let grid = style([flexDirection(Row), flexWrap(Wrap)]);

  let item =
    style([
      height(Pt(float_of_int(Dimensions.get(`window)##width / 2))),
      width(Pct(50.)),
      padding(Pt(4.)),
    ]);

  let image = style([flex(1.), resizeMode(Cover)]);
};

let photos =
  Array.make(24, "https://unsplash.it/300/300/?random&__id=")
  |> Array.mapi((index, element) => element ++ string_of_int(index));

type state = {visible: bool};

type action =
  | ToggleVisible(bool);

let component = ReasonReact.reducerComponent("BannerExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {visible: false},
  reducer: (action, _state) =>
    switch (action) {
    | ToggleVisible(visible) => ReasonReact.Update({visible: visible})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="Banner example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <ScrollView>
                 <Banner
                   visible={self.state.visible}
                   actions=[|
                     Banner.action(~label="Fix it", ~onPress=() =>
                       self.send(ToggleVisible(false))
                     ),
                     Banner.action(~label="Learn more", ~onPress=() =>
                       self.send(ToggleVisible(false))
                     ),
                   |]
                   image={
                     Banner.renderImage((props: Banner.imageProps) =>
                       <Image
                         source={
                           Required(
                             Packager.require("../assets/email-icon.png"),
                           )
                         }
                         style={
                           Style.style([
                             Style.width(Pt(props.size)),
                             Style.height(Pt(props.size)),
                           ])
                         }
                       />
                     )
                   }>
                   {
                     ReasonReact.string(
                       "Two line text string with two actions. One to two lines is preferable on mobile.",
                     )
                   }
                 </Banner>
                 <View style=Styles.grid>
                   {
                     photos
                     |> Array.map(uri =>
                          <View key=uri style=Styles.item>
                            <Image
                              source={URI(Image.imageURISource(~uri, ()))}
                              style=Styles.image
                            />
                          </View>
                        )
                     |> ReasonReact.array
                   }
                 </View>
               </ScrollView>
               <SafeAreaView>
                 <View>
                   <FAB
                     icon={Icon.Name("visibility")}
                     label={self.state.visible ? "Hide banner" : "Show banner"}
                     style=Styles.fab
                     onPress={
                       _event =>
                         self.send(ToggleVisible(!self.state.visible))
                     }
                   />
                 </View>
               </SafeAreaView>
             </View>
         }
    </StackNavigator.Screen>,
};
