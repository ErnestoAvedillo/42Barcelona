import { Vector3 } from 'three';
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader.js';
import model from '/assets/models/model.gltf';
export default class Clouds {
  constructor(scene) {
	this.loader = new GLTFLoader();
	// this.add(scene, model, new Vector3(45, 0, 0), new Vector3(0.1, 0.1, 0.1), new Vector3(0, Math.PI / 2, 0));
	// this.add(scene, model, new Vector3(-45, 0, 0), new Vector3(0.1, 0.1, 0.1), new Vector3(0, Math.PI / -2, 0));
	// this.add(scene, model, new Vector3(0, -150, 60), new Vector3(0.5, 0.5, 0.5), new Vector3(0, 0, 0));
  }
  addGameClouds(scene) {
	this.add(scene, model, new Vector3(45, 0, 0), new Vector3(0.1, 0.1, 0.1), new Vector3(0, Math.PI / 2, 0));
	this.add(scene, model, new Vector3(-45, 0, 0), new Vector3(0.1, 0.1, 0.1), new Vector3(0, Math.PI / -2, 0));
	this.add(scene, model, new Vector3(0, -150, 60), new Vector3(0.5, 0.5, 0.5), new Vector3(0, 0, 0));
}
  add(scene, path, position, scale, rotation) {
		this.loader.load(path, (gltf) => {
		scene.add(gltf.scene);
		gltf.scene.position.set(position.x, position.y, position.z);
		gltf.scene.scale.set(scale.x, scale.y, scale.z);
		gltf.scene.rotation.set(rotation.x, rotation.y, rotation.z);
		gltf.scene.traverse((child) => {
		if (child.isMesh) {
			if (child.material) {
				child.material.metalness = 0;
				child.material.roughness = 1;
				child.material.flatShading = true;
				child.frustumCulled = true;
			}
		}	
		});
		console.log(gltf.scene)
		return gltf.scene;
		},
	undefined, // Optional progress function
	() => {	console.error('An error occurred while loading the model');	});
  }
}